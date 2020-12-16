/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojoubout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:53:22 by ojoubout          #+#    #+#             */
/*   Updated: 2020/12/13 12:53:28 by ojoubout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

#define BCYN "\e[1;36m"
#define BBLU "\e[1;33m"
#define BGRN "\e[1;32m"
#define BRED "\e[1;31m"
#define RESET "\e[0m"
// #define CMD NULL
#define PIPE "|"
#define INPUT_RED "<"
#define OUTPUT_RED ">" 
#define APP_OUTPUT_RED ">>"

typedef struct  s_minishell
{ 
    int return_code;
    int stat;
    char *command_line;
    int pipe[2];
}               t_minishell;

typedef struct  s_command
{ 
    char    **argv;
    int     argc;
    char    *outRed;
    char    *inRed;
    // char    *read_next;
}               t_command;

typedef struct  s_cmd_list
{
    t_command   cmd;
    t_cmd_list   *next;
}               t_cmd_list;


t_minishell g_minishell;

void    ft_handle_cmd(char *str);
void    ft_handle_pipe(char *str);
void    ft_handle_input_red(char *str);
void    ft_handle_output_red(char *str, int app);
void    ft_error(const char *str);


int	ft_on_char(const char *str, int i, char *c);
int	ft_word_length(const char *s, char *c);
char		**ft_sh_split(char const *s, char *c);

// char	**ft_free(char **ptr, size_t size);

#endif