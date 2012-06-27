inherit ROOM;
#define DIR "/domains/newbie"

void setup(void) {
   add_area("newbie");

   set_brief("Waiting Area");
   set_long("You are in a small tunnel.  This room looks like a small " +
      "waiting area.  You hear loud noises to the north.");

   set_exits(([
      "north" : DIR + "/rooms/fighting", 
      "south" : DIR + "/rooms/quest",
   ]));

   set_objects(([
      DIR + "/obj/table":1,
   ]));
}
