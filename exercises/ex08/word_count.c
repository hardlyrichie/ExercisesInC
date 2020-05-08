#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

/* Increments the frequency associated with key */
void incr(GHashTable *hash, gchar *key)
{
    gint *val = (gint *) g_hash_table_lookup(hash, key);

    if (val == NULL)
    {
        gint *new_val = g_new(gint, 1);
        *new_val = 1;
        g_hash_table_insert(hash, key, new_val);
    } 
    else {
        *val += 1;
    }
}

void print(gpointer key, gpointer value, gpointer user_data) {
    char *word = key;
    gint *value_int = (gint *) value;
    printf("%s = %i\n", word, *value_int);
}   

int main(int argc, char** argv) {
    const gchar *filename = argv[1];
    gchar *contents;
    GError *error;

    g_file_get_contents(filename, &contents, NULL, &error);

    GHashTable *word_count = g_hash_table_new(g_str_hash, g_str_equal);

    // Replace \n with spaces, split by spaces
    gchar **split = g_strsplit(contents, "\n", -1);
    g_free(contents);
    contents = g_strjoinv(" ", split);
    g_strfreev(split);
    gchar **words = g_strsplit(contents, " ", -1);

    int i = 0;
    while (words[i] != '\0') 
    {
        incr(word_count, words[i]);
        i++;
    }

    // Print out all key value pairs in GHashTable
    g_hash_table_foreach(word_count, print, NULL);

    return 0;
}