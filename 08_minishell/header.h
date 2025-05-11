/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:06:58 by apayen            #+#    #+#             */
/*   Updated: 2023/06/02 10:19:54 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>

extern int				g_glob;

typedef struct s_cmd
{
	char				**split;
	char				**redirection;
	char				**builtin;
	struct s_cmd		*next;
	struct s_cmd		*back;
	struct s_shell		*ms;
}						t_cmd;

typedef struct s_expand
{
	int					i;
	int					j;
	char				c;
	char				pad[7];
	char				*split[3];
	char				*tmp;
	char				*buff;
	struct s_lst		*node;
	struct s_heredoc	*hd;
	struct s_shell		*ms;
}						t_expand;

typedef struct s_heredoc
{
	int					i;
	int					fd;
	int					isend;
	int					state;
	char				*name;
	char				*line;
	struct s_shell		*ms;
	int					backup;
	char				pad[4];
}						t_heredoc;

typedef struct s_tokens
{
	char				*token;
	char				*file;
	char				*pipe;
	int					ambi;
	char				pad[4];
}						t_tokens;

typedef struct s_lexer
{
	char				*str;
	char				**tab;
	t_tokens			token;
	int					i;
	int					len;
	struct s_lexer		*next;
	struct s_lexer		*back;
}						t_lexer;

typedef struct s_lst
{
	char				*line;
	struct s_lst		*next;
	struct s_shell		*ms;
	int					print;
	int					pad;
}						t_lst;

typedef struct s_redir
{
	struct s_tokens		token;
	struct s_redir		*next;
	struct s_redir		*back;
}						t_redir;

typedef struct s_cmd_lst
{
	char				**tab;
	char				*name;
	struct s_redir		*redirlst;
	struct s_cmd_lst	*next;
	int					i;
	int					*fd;
	char				pad[4];
}						t_cmd_lst;

typedef struct s_pipex
{
	int					count;
	int					i;
	int					eror;
	int					in[2];
	int					out;
	int					bhole;
	int					in_rok;
	int					out_rok;
	int					out_red;
	int					pipe;
	int					cmd_i;
	int					**fds;
	int					fd[2];
	int					nb_cmd;
	int					hdoc;
	pid_t				*pids;
	int					ac;
	char				pad[4];
	char				*limit;
	char				*cmd_join;
	char				**s_ev;
	char				**ev;
	char				**av;
	struct s_cmd_lst	*head;
	struct s_cmd_lst	*headplus;
	struct s_cmd_lst	*cmd;
	struct s_redir		*tokenhead;
	struct s_shell		*ms;
}						t_pipex;

typedef struct s_shell
{
	char				*line;
	char				*pwdpath;
	char				*oldpwdpath;
	char				**tabenv;
	char				*tmp;
	int					error;
	int					status;
	struct s_lst		*env;
	struct s_lexer		*head;
	struct s_tokens		token;
	struct s_heredoc	*hd;
	struct s_pipex		*pex;
	struct s_lexer		*lexer;
	struct sigaction	sigact[5];
}						t_shell;

// *************************  PROGRAM  ************************* //
// program/init.c
int				ft_nb_cmd(t_lexer *lexer);
void			ft_lstadd_back(struct s_shell *ms, t_lst **lst, t_lst *new);
struct s_lst	*ft_lstnew(struct s_shell *ms, char *str);
t_tokens		ft_newtoken(char *token, char *file);
void			init(struct s_shell *ms, char **envp);
// program/init_env.c
void			increaseshlvl(struct s_shell *ms);
void			ft_setpwd(struct s_shell *ms);
void			recreatepwd(struct s_shell *ms);
void			createminienv(struct s_shell *ms);
void			ft_setenv(struct s_shell *ms, char **envp);
// program/loop.c
int				execution(struct s_shell *ms, struct s_lexer *lexer);
int				parser(struct s_shell *ms);
void			nullonreadline(struct s_shell *ms);
void			loop(struct s_shell *ms);
// program/minishell.c
void			setsigaction(struct s_shell *ms, int b);
int				main(int argc, char **argv, char **envp);
// program/signals.c
void			ft_sigquit(int sig);
void			ft_sigint_heredoc(int sig);
void			ft_sigint2(int sig);
void			ft_sigint(int sig);
void			*ft_memset(void *s, int c, size_t n);

// *************************  PARSING  ************************* //
// parsing/checkorphans.c
int				printsyntaxerror(char *line, int i);
int				isspecial(char c);
int				checkorphanquote(char *line);
int				checkorphanbracket(char *line);
int				checkorphans(char *line);
// parsing/checkorphans2.c
int				checkorphanredir(char *line);
int				checkorphanpipe(char *line);
int				checkorphanredir_skip(char *str, int i);
// parsing/expand_dquote.c
int				ft_expand_ambiguous(struct s_expand *exp, char *str);
void			ft_expand_dquotereplace(struct s_expand *exp);
void			ft_expand_dquote(struct s_expand *exp, char *str);
// parsing/expand_utils.c
void			ft_expand_error(struct s_expand *exp);
char			*ft_expand_join(struct s_expand *exp, char *s1, char *s2);
int				ft_isalnum(int c);
int				isexp(struct s_expand *exp, char *str, int i, int j);
void			ft_expand_initstruct(struct s_expand *exp, t_shell *ms, \
				t_lexer *lex);
// parsing/expand.c
void			ft_expand_dollar(struct s_expand *exp, char *str);
void			ft_expand_replace(struct s_expand *exp, char *str);
void			ft_expand_init(struct s_expand *exp, char *str, int i, int j);
char			*ft_expand_start(struct s_expand *exp, char *str);
void			ft_expand(struct s_lexer *lexer, struct s_shell *ms);
// parsing/heredoc_utils.c
void			ft_expheredoc_init(struct s_expand *exp, char *str);
char			*ft_heredoc_expand(struct s_heredoc *hd, char *str);
void			ft_heredoc_filename(struct s_shell *ms, char *str);
int				ft_heredoc_quotes(char *str, int i, int len);
int				ft_heredoc_delim(char *str);
// parsing/heredoc.c
void			ft_heredoc_remove(struct s_lexer *lexer);
int				ft_heredoc_end(struct s_shell *ms, char *delim, \
				struct s_heredoc *hd);
int				ft_heredoc_loop(struct s_shell *ms, char *delim, \
				struct s_heredoc *hd);
void			ft_heredoc_init(struct s_shell *ms, struct s_heredoc *hd, \
				int b);
void			ft_heredoc(struct s_lexer *lexer, struct s_shell *ms);
// parsing/lst_lexer.c
t_lexer			*ft_lstlast_lexer(t_lexer *head);
void			ft_lstresetindex_lexer(t_lexer *head);
t_lexer			*ft_lexer_new(char *str, t_tokens token);
void			ft_lexer_addback(t_lexer **head, t_lexer *new, t_shell *ms);
void			ft_lexer_delone(t_lexer **curr_node, int i);
// parsing/parsing.c
int				ft_state(char c, int state);
int				ft_istoken(char c);
int				ft_isthereatoken(char *line, t_lexer **lexer, t_shell *ms);
void			ft_browse(t_shell *ms);
// parsing/tokens.c
int				ft_goodtoken(t_shell *ms, char *line, t_tokens *token, \
				char **word);
int				ft_goodword(char *line, t_tokens *token, char **word, \
				int state);
void			ft_add_tokenword(t_lexer *lexer, t_shell *ms);
void			ft_add_word_to_tab(t_lexer *lexer, t_shell *ms);
void			ft_tabptr(t_shell *ms, t_lexer *node_cmd, t_lexer *tmp, \
				int nb_tab);

// *************************   PIPEX   ************************* //
// pipex/pipex_close.c
void			ft_free_process(t_pipex *m);
void			ft_close_file(t_cmd_lst *cmd);
void			ft_closeoutin(t_pipex *m);
void			ft_closefds(t_pipex *m);
void			ft_freefds(t_pipex *m);
// pipex/pipex_init.c
int				ft_init_cmd(t_pipex *m, t_shell *ms, int nb_cmd);
void			ft_mallocpipe(t_pipex *m);
void			ft_which_builtin(char **tab, t_shell *ms);
char			*ft_isabuiltin(char **tab, t_shell *ms, int state);
t_pipex			*ft_init(t_pipex *m, int nb_cmd, char **env);
// pipex/pipex_lst.c
t_cmd_lst		*ft_pipex_lstnew(char **cmd, char *name, int i);
t_cmd_lst		*ft_lstlast(t_cmd_lst *lst);
void			ft_pipex_lstadd_back(t_cmd_lst **lst, t_cmd_lst *new, \
				t_pipex *m);
void			ft_lstclearpipex(t_cmd_lst **lst);
int				ft_lstsize(t_redir *lst);
// pipex/pipex_open.c
int				ft_openin(t_pipex *m, t_redir *redir, t_cmd_lst *cmd);
int				ft_openout(t_pipex *m, t_redir *redir, t_cmd_lst *cmd);
void			ft_dupcheck(int fd, int stdfd, t_pipex *m);
int				ft_open_redir(t_cmd_lst *tmp, t_pipex *m);
int				ft_dup_redir(t_pipex *m, t_cmd_lst *cmd);
// pipex/pipex_parsing.c
char			**ft_find_nodecmd(t_lexer **lexer, t_shell *ms);
int				ft_access_while(t_pipex *m, char **tab, int p);
void			ft_access(t_pipex *m, char **tab, int p);
void			ft_checkaccees(t_pipex *m, t_lexer **lexer, char **tab);
void			ft_fake_command(t_pipex *m, t_shell *ms, char **tab, \
				char *name);
// pipex/pipex_parsing2.c
t_redir			*ft_redir_lstnew(t_tokens token);
t_redir			*ft_redir_lstlast(t_redir *lst);
void			ft_redir_lstadd_back(t_redir **lst, t_redir *new, t_pipex *m);
void			ft_redir_in_cmd(t_pipex *m, t_lexer **lexer, t_cmd_lst *cmd);
void			ft_redir_list(t_pipex *m, t_shell *ms);
// pipex/pipex_parsing3.c
int				ft_exitprotection(t_shell *ms, char **tab, int in, int out);
void			ft_cmd_list(t_pipex *m, t_shell *ms);
void			find_cmd(t_pipex *m, t_shell *ms);
// pipex/pipex_util.c
void			ft_pipe(t_pipex *m);
int				ft_fdspipe(t_pipex *m);
void			ft_fork(t_pipex *m);
void			ft_childprocess(t_pipex *m);
void			ft_cmdex(char **cmd, char **ev, t_pipex *m, int dup_redir);
// pipex/pipex_util2.c
char			*ft_pipex_strlcpy(char *dest, const char *src);
char			*ft_pipex_strlcat(char *dest, const char *src, int size);
char			*ft_pipex_join(char *path, char *cmd);
char			**ft_realloc_tab(char **tab, char **curr_tab);
// pipex/pipex.c
void			ft_process(t_pipex *m);
void			ft_exec(t_pipex *m, t_shell *ms);
void			ft_pipe_exec(t_pipex *m, t_shell *ms);
int				ft_end(t_shell *ms);
int				ft_start(t_shell *ms);

// ************************* BUILT-INS ************************* //
// builtins/builtins_cd.c
int				ft_cd_home(struct s_shell *ms, char *tmp);
int				ft_cd_oldpwd(struct s_shell *ms, char *tmp, int b);
int				ft_cd_nothome(struct s_shell *ms, char *str, char *tmp);
int				ft_cd(struct s_shell *ms, char **tab);
// builtins/builtins_cd2.c
void			ft_cd_actualizepwd(struct s_shell *ms);
void			ft_cd_changeenv(struct s_shell *ms, char *tmp, char *str);
void			ft_cd_actualizeenv(struct s_shell *ms, char *tmp);
int				ft_cd_removedparent(struct s_shell *ms, char **tab, char *tmp);
char			*ft_cd_proteccwd(struct s_shell *ms, char **tab, char *tmp);
// builtins/builtins_echo.c
int				ft_echo_isfulln(char *str);
int				ft_echo_option(char	**tab, int *n);
int				ft_echo(char **tab);
// builtins/builtins_exit.c
void			ft_exit_free(struct s_shell *ms);
void			ft_exit_checktab(struct s_shell *ms, char *str, int i);
int				ft_exit(struct s_shell *ms, char **tab);
// builtins/builtins_export.c
int				ft_export_newnode(struct s_shell *ms, char *str);
int				ft_export_oldnode(struct s_lst *node, char *str);
int				ft_export_refreshenv(struct s_shell *ms, char *str, int equal);
int				ft_export(struct s_shell *ms, char **tab);
// builtins/builtins_export2.c
int				ft_export_isvalid(char c, int i);
int				ft_export_searchequal(char *str);
int				ft_export_parsing(char *str);
// builtins/builtins.c
int				ft_pwd(struct s_shell *ms);
int				ft_unset(struct s_shell *ms, char **tab);
int				ft_env(struct s_shell *ms, char **tab);

// *************************   UTILS   ************************* //
// utils/errors_1-5.c
void			ft_errors_redir(t_pipex *m, t_redir *redir, \
				int in_out, t_cmd_lst *cmd);
void			ft_exitchild(t_pipex *m, int status_code);
void			ft_error(char *file, char *error, int pid, t_pipex *m);
// utils/frees.c
void			ft_lstclear(struct s_lst *lst);
void			ft_lexerclear(t_lexer *lexer);
void			freesplit(char **strmalloc);
void			frees(struct s_shell *ms, int code);
void			throwerror(struct s_shell *ms, char *str);
// utils/ft_split.c
char			**ft_split(char *s, char c);
// utils/lst.c
t_cmd			*ft_lstnew_cmd(char **str, char **redir, char **built);
void			ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new);
// utils/minilib.c
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_strcmp(char *s1, char *s2);
char			*ft_tabcmp(char *str, char **tab);
char			*ft_strnstr_cmp(char *big, char *little, int len);
// utils/utils_env2.c
int				countvalablenodes(struct s_lst *lst);
char			**listtotab(struct s_shell *ms);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_subnstr(char *s, unsigned int start, size_t len);
// utils/utils_env.c
char			*ft_strjoinenv(char *s1, char c, char *s2);
char			*ft_itoa(int nb);
char			*ft_substr(char *s, int start, int len);
char			*ft_strnstr(char *big, char *little, int equal);
struct s_lst	*ft_getenv(struct s_shell *ms, char *str);
// utils/utils.c
int				ft_strlen(char *str);
int				ft_tablen(char **str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *s);
long long int	ft_atoi(char *nptr, int *b);

void			print_allcmd(t_pipex *m);
#endif
