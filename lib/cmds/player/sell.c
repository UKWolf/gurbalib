void usage() {
   string *lines;
   lines = ({ "Usage: sell [-h] OBJ" });
   lines += ({ "Allows you to sell an object OBJ, " +
      "assuming you are near a shop keeper." });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\tsell sword" });
   lines += ({ "\tsell helmet" });
   lines += ({ "See also: buy, identify, list, look, retrieve, sell, " +
      "store, value" });

   this_player()->more(lines);
}

/* Created by Fudge */

void main(string str) {
   object *objs;
   object obj;
   int i;

   if (!str || str == "") {
      usage();
      return;
   }

   if (sscanf(str, "-%s", str)) {
      usage();
      return;
   }

   obj = this_player()->present(str);
   if (obj) {
      /* Found the item */

      objs = this_environment()->query_inventory();
      for (i = 0; i < sizeof(objs); i++) {
	 if (objs[i]->is_vendor() == 1) {
	    /* Found the shopkeeper */

	    if (obj->is_worn()) {
	       this_player()->do_remove(obj);
	       this_player()->targetted_action(obj->query_remove_message(), nil,
		  obj);
	    }

	    if (obj->is_wielded()) {
	       this_player()->do_unwield(obj);
	       this_player()->targetted_action(obj->query_unwield_message(),
		  nil, obj);
	    }

	    if (obj->is_undroppable()) {
	       this_player()->
		  targetted_action("$N $vare unable to let go of $o.", nil,
		  obj);
	       return;
	    }

	    objs[i]->do_buy(this_player(), obj);
	    return;

	 }
      }
      write("Sell to who?");
   }
   write("You don't have that.");
}
