void usage() {
  write("Usage: where [-h] [player]\n");
  write("Locates the given [player] and prints out their location.\n");
  write("If [player] is omitted it prints out everyones location.\n");
  write("Options:\n");
  write("\t-h\tHelp, this usage message.\n");
}

void main( string str ) {
  int i;
  object *usrs;
  object usr;

  if (!str || (str == "")) {
    usrs = USER_D->query_users();

    for( i = 0; i < sizeof( usrs ); i++ ) {
      write( capitalize( usrs[i]->query_name() ) + " "
	   + usrs[i]->query_player()->query_environment()->query_brief() + " "
	   + usrs[i]->query_player()->query_environment()->base_name() + "\n"
	   );
    }
  } else {
     if (sscanf(str, "-%s",str)) {
        usage();
     } else if (usr = USER_D->find_user(str) ) {
        write( capitalize( usr->query_name() ) + " "
	   + usr->query_player()->query_environment()->query_brief() + " "
	   + usr->query_player()->query_environment()->base_name() + "\n"
	   );
     } else {
        write("Who are you looking for?  I can't find: " + str + "!\n");
     }
  }
}
