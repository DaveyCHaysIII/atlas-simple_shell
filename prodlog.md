Davey 3/20:
Got a lot of research done on fork(), execve(), PID and basic shell loop
Davey 3/21: 
Got further research done, started super simple shell (see testing), created repo
3/23 Chase and Davey met in Assembly 10 am-12pm:
Talked about expectations, parsed up workload got the flow of the shell laid out.

Chase 3/23:
working in repo intermittently on getting a flow chart set up and uploaded.
Flow Chart will require more research than expected but I believe a solid, not finished, README has been accomplished.

Davey 3/24: 
supersimpleshell now works! you can try commands 'ls' and 'exit'! 
-we need to create a more dynamic way of plugging in commands, and to do that we need a function that can take a single string and concatenate it with the beginning of a path, like so: 

char *findpath( char *command)
{
...
return ("/usr/bin/command");
}

and handle the errors if execve fails. I'm going to do some more research and then try to do this tonight. I'm not sure at this moment what "interactive" mode even really means or how we'll have to shape our code to accomodate it but I'll try and get that figured out asap.

Davey 3/25

ignore previous entry, it makes much more sense to check if the command exists prior to forking in the first place, plus the 30pt question requires it. Added an implementation of getenv() since it wasn't on the list of approved functions. This'll give us quick and dirty access to PWD, HOME, PATH and many other environment variables we may need along the way. 

The entire testing folder is meant to be a messy leaky random assembly of code we can pick through, I'm gonna be populating it a lot more going foreward so we have little working code snippets and main files we can use to test on  
