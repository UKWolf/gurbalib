void usage() {
   string *lines;

   lines = ({ "Usage: wall [-h] MSG" });
   lines += ({ "Tell everyone on the mud: MSG." });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "\t-w\tRestrict the MSG to sending only to wizards, " +
      "not normal players." });
   lines += ({ "Examples:" });
   lines += ({ "\twall We are upgrading the server in 10 minutes." });
   lines += ({ "See Also: shout, tell" });

   this_player()->more(lines);
}

void main(string str) {
   object *users;
   int i, max;

   if (!str || str == "") {
      usage();
      return;
   }
   if (sscanf(str, "-w %s", str)) {
      if (!require_priv("system")) {
	 write("You need admin permissions to do that.");
	 return;
      }

      users = USER_D->query_wizards();

      max = sizeof(users);
      for (i = 0; i < max; i++) {
	 users[i]->message("WALL from " +
	    this_player()->query_Name() + ": " + str + "\n");
      }

      return;
   }

   if (sscanf(str, "-%s", str)) {
      usage();
      return;
   }

   if (!require_priv("system")) {
      write("You need admin permissions to do that.");
      return;
   }

   users = USER_D->query_players();
   max = sizeof(users);
   for (i = 0; i < max; i++) {
      users[i]->message("WALL from " +
	 this_player()->query_Name() + ": " + str + "\n");
   }
}
