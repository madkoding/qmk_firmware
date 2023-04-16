#pragma once

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _UP:
            rgb_matrix_set_color(49, 200, 0, 0); // ; - right
            rgb_matrix_set_color(55, 200, 0, 0); // O - up
            rgb_matrix_set_color(54, 200, 0, 0); // L - down
            rgb_matrix_set_color(59, 200, 0, 0); // K - left
            rgb_matrix_set_color(10, 100, 100, 100); // Esc
            rgb_matrix_set_color(11, 100, 100, 100); // 1
            rgb_matrix_set_color(20, 100, 100, 100); // 2
            rgb_matrix_set_color(21, 100, 100, 100); // 3
            rgb_matrix_set_color(30, 100, 100, 100); // 4
            rgb_matrix_set_color(31, 100, 100, 100); // 5
            rgb_matrix_set_color(67, 100, 100, 100); // 6
            rgb_matrix_set_color(66, 100, 100, 100); // 7
            rgb_matrix_set_color(57, 100, 100, 100); // 8
            rgb_matrix_set_color(56, 100, 100, 100); // 9
            rgb_matrix_set_color(47, 100, 100, 100); // 0
            rgb_matrix_set_color(46, 100, 100, 100); // Del
            break;
        case _DOWN:
            rgb_matrix_set_color(49, 200, 0, 0); // ; - right
            rgb_matrix_set_color(55, 200, 0, 0); // O - up
            rgb_matrix_set_color(54, 200, 0, 0); // L - down
            rgb_matrix_set_color(59, 200, 0, 0); // K - left
            break;
        case _LEFT:
            break;
        case _RIGHT:
            rgb_matrix_set_color(13, 0, 255, 0); // A
            rgb_matrix_set_color(22, 0, 255, 0); // E
            rgb_matrix_set_color(58, 0, 255, 0); // I
            rgb_matrix_set_color(55, 0, 255, 0); // O
            rgb_matrix_set_color(65, 0, 255, 0); // U
            rgb_matrix_set_color(70, 0, 255, 0); // N
            rgb_matrix_set_color(53, 0, 255, 0); // .
            rgb_matrix_set_color(60, 0, 255, 0); // ,
            rgb_matrix_set_color(56, 0, 255, 0); // 9
            rgb_matrix_set_color(47, 0, 255, 0); // 0
            rgb_matrix_set_color(50, 0, 255, 0); // /
            break;
        case _TUNE:
            break;
        case _BASE:
            rgb_matrix_set_color(13, 200, 0, 0); // A
            rgb_matrix_set_color(19, 200, 0, 0); // W
            rgb_matrix_set_color(18, 200, 0, 0); // S
            rgb_matrix_set_color(23, 200, 0, 0); // D
            rgb_matrix_set_color(11, 200, 0, 0); // 1
            rgb_matrix_set_color(20, 200, 0, 0); // 2
            rgb_matrix_set_color(21, 200, 0, 0); // 3
            rgb_matrix_set_color(30, 200, 0, 0); // 4
            rgb_matrix_set_color(31, 200, 0, 0); // 5
            rgb_matrix_set_color(67, 200, 0, 0); // 6
            rgb_matrix_set_color(66, 200, 0, 0); // 7
            rgb_matrix_set_color(57, 200, 0, 0); // 8
            rgb_matrix_set_color(56, 200, 0, 0); // 9
            rgb_matrix_set_color(47, 200, 0, 0); // 0
            break;
    }
    return false;
}
#endif
