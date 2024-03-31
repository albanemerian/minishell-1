# minishell-1

{EPITECH} | First year | Unix System programming project

You have to program a UNIX command interpreter. The interpreter is expected to display a prompt ( $> , for example) and then wait for you to write a command line, which must be validated by a newline.

The prompt must be displayed again only after the command execution. Only basic command lines are expected to executed; no pipes, redirections or any other advanced features. The executables should be those found in the path, as indicated in the PATH variable.

If the executable cannot be found, you must display an error message and display the prompt again. Errors must be dealt with and must display the appropriate message on the error output.

You must correctly handle the PATH and the environment (by copying and restoring the initial env). You must implement the following builtins: cd, setenv, unsetenv, env, exit.

See the subject for further details !
Usage :  make
        ./mysh

========================
1st semester Unix System programming (part II) unit

| Category                         | Percentage | Tests | Crash |
|----------------------------------|------------|-------|-------|
| Basic tests                      | 100%       | 5/5   | x     |
| Path handling                    | 100%       | 5/5   | x     |
| Path handling eval               | 100%       | 5/5   | x     |
| Setenv and unsetenv              | 100%       | 2/2   | x     |
| Setenv and unsetenv              | 100%       | 2/2   | x     |
| Builtin cd                      | 100%       | 3/3   | x     |
| Builtin cd eval                 | 100%       | 3/3   | x     |
| Line formatting (space and tabs) | 100%       | 8/8   | x     |
| Line formatting (space and tabs) eval | 100%  | 8/8   | x     |
| Error handling                  | 100%       | 5/5   | x     |
| Error handling eval             | 100%       | 5/5   | x     |
| End scores                      | 100%       | 51/51 | x     |


Beware of -42 Epitech students !!!
