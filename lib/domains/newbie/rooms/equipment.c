inherit ROOM;
#define DIR "/domains/newbie"

void setup(void) {
   add_area("newbie");

   set_brief("A narrow passage");
   set_long("You are in a small tunnel.  It was a tight squeeze to get in " +
      "here.");

   set_exits(([
      "north" : DIR + "/rooms/entrance", 
      "south" : DIR + "/rooms/fighting",
   ]));
}
