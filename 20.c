#include <stdio.h>

int main() { //read the no. of post
    int post;
    scanf("%d", &post);

    int likes[post], comments[post]; // arrays to store likes and comments for each post
    for (int i = 0; i < post; i++) {
        scanf("%d", &likes[i]);
    }
    for (int i = 0; i < post; i++) {
        scanf("%d", &comments[i]);
    }

    int max_likes = likes[0];
    int max_comments = comments[0];
    int popular_index = 1;

    for (int i = 1; i < post; i++) { // finding most popular one
        if (likes[i] > max_likes) {
            max_likes = likes[i];
            max_comments = comments[i];
            popular_index = i + 1;
        } else if (likes[i] == max_likes && comments[i] > max_comments) {
            max_comments = comments[i];
            popular_index = i + 1;
        }
    }

    printf("%d\n", popular_index); //print the index of most popular post
    return 0;
}