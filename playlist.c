#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

struct Song {
    const char *artist;
    const char *title;
    int year;
    struct Song* next;
};

void addSong(struct Song **node, const char *artist, const char *title, int year) {
    struct Song *newsong = malloc(sizeof(struct Song));

    newsong->artist = artist;
    newsong->title = title;
    newsong->year = year;
    newsong->next = *node;
    *node = newsong;

}

void printPlaylist(struct Song *node) {
    int i = 1;
    while (node != NULL) {
        printf("\nSong #%d \n",i++);
        printf("\nArtist: %s \n", node->artist);
        printf("Title: %s \n", node->title);
        printf("Year: %d \n", node->year);
        printf("------------------------------------\n");
        node = node->next;
    }
}

void deleteSong(struct Song **node, const char *title) {
    printf("Deleting song with title: \"%s\". . . \n", title);

    for (struct Song *cur = *node, *prev = NULL; cur != NULL; prev = cur, cur = cur->next) {
        if (strcmp(cur->title, title) == 0) {
            if (prev == NULL) {
                *node = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            return;
        }
    }

    printf("Song not found.\n");
}

int main(void) {
    struct Song *node = NULL;

    addSong(&node, "MILI", "Rendezvous", 2026);
    addSong(&node, "The Long Faces", "Jane!", 2018);
    addSong(&node, "The Handsome Devil", "Charlie's Inferno", 2011);

    printPlaylist(node);

    deleteSong(&node, "Jane!");

    printPlaylist(node);

    return 0;
}