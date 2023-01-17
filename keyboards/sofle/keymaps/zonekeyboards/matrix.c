#pragma once

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    rgb_matrix_enable();
    rgb_matrix_set_color(13, 255, 0, 0); // W
    rgb_matrix_set_color(19, 255, 0, 0); // A
    rgb_matrix_set_color(18, 255, 0, 0); // S
    rgb_matrix_set_color(23, 255, 0, 0); // D
    rgb_matrix_set_color(49, 255, 0, 0); // O - up
    rgb_matrix_set_color(55, 255, 0, 0); // K - left
    rgb_matrix_set_color(54, 255, 0, 0); // L - down
    rgb_matrix_set_color(59, 255, 0, 0); // ; - right
    return false;
}
#endif