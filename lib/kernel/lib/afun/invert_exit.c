string invert_exit( string exit ) {
  argcheck( exit, 1, "string" );
  switch( exit ) {
  case "north":
    return( "south" );
  case "south":
    return( "north" );
  case "east":
    return( "west" );
  case "west":
    return( "east" );
  case "northeast":
    return( "southwest" );
  case "southeast":
    return( "northwest" );
  case "northwest":
    return( "southeast" );
  case "southwest":
    return( "northeast" );
  }
  return( "unknown" );
}

