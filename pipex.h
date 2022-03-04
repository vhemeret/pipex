/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:02:40 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/04 20:29:53 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_struct
{
	int		pipefd[2];
	int		infile;
	int		outfile;
	int		child1;
	int		child2;
	int		flag1;
	int		flag2;
	int		cmd1_is_invalid;
	int		cmd2_is_invalid;
	int		is_quote;
	char	**envp;
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
	char	*cmd1_flag;
	char	*cmd2_flag;
	char	*path_cmd1;
	char	*path_cmd2;
	char	**cmd1_tab;
	char	**cmd2_tab;
}				t_struct;

/*####################### MANDATORY PART #######################*/

/* PARSING */
int		check_error(int ac, char **av, char **env, t_struct *data);
int		get_env(char **env, t_struct *data);
void	check_cmd(t_struct *data, char **av);
int		check_directory(char *path_file, int file);
int		check_file1(char *path_file);
int		check_file2(t_struct *data);
void	manage_quote(t_struct *data, char c);
int		get_cmd1(t_struct *data, char *cmd);
int		get_cmd2(t_struct *data, char *cmd);
void	put_arg_tab(t_struct *data, char **tab, char *cmd);
int		check_access_cmd1(t_struct *data, char *cmd);
int		check_access_cmd2(t_struct *data, char *cmd);
int		check_if_flag(char *cmd);

/* UTILS */
char	*to_find(char *str, char *to_find);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *path, char *cmd);
char	*extract_str(char *str, int to_find);
char	*extract_flag(char *cmd);
int		ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);

/* CLEANING */
void	cleaning(t_struct *data);
void	cleaning_success(t_struct *data);
int		free_str(char *str);
char	**free_double_tab(char **tab);

/* PROCESS */
int		pipex(t_struct *data, char **envp);

#endif
