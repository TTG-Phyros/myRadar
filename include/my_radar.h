/*
** EPITECH PROJECT, 2022
** my radar
** File description:
** my_radar
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_

    // ! includes
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <stdio.h>

    // * Macros
    #define wallpaper "./content/mother_earth.png"

    // ? Structures
    typedef struct plane plane;
    struct plane {
        int x_dep;
        int y_dep;
        int x_fin;
        int y_fin;
        int speed;
        int delay;
        int hitbox_option;
        int sprite_option;
        float rotation;
        float *ratio;
        float *already_moved;
        sfSprite *pl_sp;
        sfRectangleShape *hitbox;
        sfClock *d_clock;
        plane *next;
    };

    typedef struct tower tower;
    struct tower {
        int x_dep;
        int y_dep;
        int radius;
        int hitbox_option;
        int sprite_option;
        sfSprite *to_sp;
        sfCircleShape *hitbox;
        tower *next;
    };

    typedef struct list_pl list_pl;
    struct list_pl {
        plane *first;
    };

    typedef struct list_to list_to;
    struct list_to {
        tower *first;
    };

    // TODO Functions

    // data_grab.c
    char **c_one_is_trash(char **map, int k, int i_and_j[2], char *str);
    char **str_to_word_array(char *str, char c);
    char *file_to_str(char *filepath);
    int nb_lines_file(char *buffer);
    int data_grab(char **argv, list_pl *list_plane, list_to *list_tower);

    // data_grab_sec.c
    int my_int_array_len(int *array);
    int *get_data_int(char *line);

    // plane_related.c
    void plane_orientation(plane *plane);
    void draw_planes(list_pl *plane_list, sfRenderWindow *window,
                    list_to *l_to);
    list_pl *initialisation_plane(list_pl *list_plane);
    void insertion_plane(list_pl *list_plane, char *line);

    // tower_related.c
    list_to *initialisation_tower(list_to *list_tower);
    void insertion_tower(list_to *list_tower, char *line);
    void draw_towers(list_to *tower_list, sfRenderWindow *window);

    // my_strlen.c
    int my_strlen(char const *str);
    int my_intlen(int nb);
    int my_strcmp(char *str_o, char *str_t);
    char *int_to_str(int nb);

    // display.c
    void display_plane(list_pl *list_plane);
    void display_tower(list_to *list_tower);

    // graphic_part.c
    void close_event(sfEvent event, sfRenderWindow *window,
                    list_pl *planes, list_to *towers);
    sfRenderWindow *window_init(void);
    void graphic_part(list_pl *plane_list, list_to *tower_list);

    // sprites_init.c
    sfSprite *set_ss(char *fp, int *pos_sp, int *dim_sp, float *scale_sp);
    void plane_sprites_init(list_pl *list_plane);
    void tower_sprites_init(list_to *tower_list);
    sfSprite *wallpaper_init(void);

    // moving_sprite.c
    void move_planes(plane *ac_plane, float sec);
    void check_if_finished(plane *ac_plane);
    void check_collision(list_pl *pl_l, list_to *li_to, sfRenderWindow *window);

    //text.c
    sfText *set_text(float secs);
    sfText *change_text(sfText *text, float secs);

#endif
