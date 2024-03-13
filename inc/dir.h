#pragma once


namespace s2 {
    enum class dir;


    enum class dir {
        up,
        down,
        left,
        right
    };


    constexpr bool is_direction_on_xaxis(const dir _dir) {
        return ((_dir == dir::left) || (_dir == dir::right));
    }
    
    constexpr bool is_direction_on_yaxis(const dir _dir) {
        return ((_dir == dir::up) || (_dir == dir::down));
    }
}
