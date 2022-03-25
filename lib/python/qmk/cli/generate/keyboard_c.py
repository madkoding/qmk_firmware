"""Used by the make system to generate keyboard.c from info.json.
"""
from milc import cli

from qmk.info import info_json
from qmk.commands import dump_lines
from qmk.keyboard import keyboard_completer, keyboard_folder
from qmk.path import normpath
from qmk.constants import GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE


def _gen_led_config(info_data):
    """Convert info.json content to g_led_config
    """
    cols = info_data['matrix_size']['cols']
    rows = info_data['matrix_size']['rows']

    if 'layout' in info_data.get('rgb_matrix', {}):
        led_config = info_data['rgb_matrix']['layout']
    elif 'layout' in info_data.get('led_matrix', {}):
        led_config = info_data['led_matrix']['layout']

    lines = []
    if not led_config:
        return lines

    matrix = [['NO_PIN'] * cols for i in range(rows)]
    pos = []
    flags = []

    for index, item in enumerate(led_config, start=0):
        if 'matrix' in item:
            (x, y) = item['matrix']
            matrix[x][y] = str(index)
        pos.append(f'{{ {item.get("x", 0)},{item.get("y", 0)} }}')
        flags.append(str(item.get('flags', 0)))

    lines.append('__attribute__ ((weak)) led_config_t g_led_config = {')
    lines.append('  {')
    for line in matrix:
        lines.append(f'    {{ {",".join(line)} }},')
    lines.append('  },')
    lines.append(f'  {{ {",".join(pos)} }},')
    lines.append(f'  {{ {",".join(flags)} }},')
    lines.append('};')

    return lines


@cli.argument('-o', '--output', arg_only=True, type=normpath, help='File to write to')
@cli.argument('-q', '--quiet', arg_only=True, action='store_true', help="Quiet mode, only output error messages")
@cli.argument('-kb', '--keyboard', arg_only=True, type=keyboard_folder, completer=keyboard_completer, required=True, help='Keyboard to generate keyboard.c for.')
@cli.subcommand('Used by the make system to generate keyboard.c from info.json', hidden=True)
def generate_keyboard_c(cli):
    """Generates the keyboard.h file.
    """
    kb_info_json = info_json(cli.args.keyboard)

    # Build the layouts.h file.
    keyboard_h_lines = [GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE, '#include QMK_KEYBOARD_H', '']

    keyboard_h_lines.extend(_gen_led_config(kb_info_json))

    # Show the results
    dump_lines(cli.args.output, keyboard_h_lines, cli.args.quiet)