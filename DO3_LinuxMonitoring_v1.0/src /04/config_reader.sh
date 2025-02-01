#!/bin/bash

config_file="config.conf"

default_col1_bg=6
default_col1_fg=3
default_col2_bg=6
default_col2_fg=3 

read_config() {
    if [[ -f $config_file ]]; then
        source "$config_file"
    fi

    column1_background=${column1_background:-$default_col1_bg}
    column1_font_color=${column1_font_color:-$default_col1_fg}
    column2_background=${column2_background:-$default_col2_bg}
    column2_font_color=${column2_font_color:-$default_col2_fg}

    [[ -n "$(grep 'column1_background' $config_file 2>/dev/null)" ]] && col1_bg_text="$column1_background" || col1_bg_text="default"
    [[ -n "$(grep 'column1_font_color' $config_file 2>/dev/null)" ]] && col1_font_text="$column1_font_color" || col1_font_text="default"
    [[ -n "$(grep 'column2_background' $config_file 2>/dev/null)" ]] && col2_bg_text="$column2_background" || col2_bg_text="default"
    [[ -n "$(grep 'column2_font_color' $config_file 2>/dev/null)" ]] && col2_font_text="$column2_font_color" || col2_font_text="default"
}
