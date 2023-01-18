#pragma once

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _UP:
            rgb_matrix_set_color(49, 255, 0, 0); // ; - right
            rgb_matrix_set_color(55, 255, 0, 0); // O - up
            rgb_matrix_set_color(54, 255, 0, 0); // L - down
            rgb_matrix_set_color(59, 255, 0, 0); // K - left
            break;
        case _DOWN:
            rgb_matrix_set_color(49, 255, 0, 0); // ; - right
            rgb_matrix_set_color(55, 255, 0, 0); // O - up
            rgb_matrix_set_color(54, 255, 0, 0); // L - down
            rgb_matrix_set_color(59, 255, 0, 0); // K - left
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
            rgb_matrix_set_color(13, 255, 0, 0); // A
            rgb_matrix_set_color(19, 255, 0, 0); // W
            rgb_matrix_set_color(18, 255, 0, 0); // S
            rgb_matrix_set_color(23, 255, 0, 0); // D
            break;
    }
    return false;
}
#endif
// 68 y
// 63 m
