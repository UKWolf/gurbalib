void main( string str ) {
  if( str == "" ) {
    write( "Useage: mkwiz <name>\n" );
    return;
  }
  if( SECURE_D->query_admin( this_player()->query_name() ) == 1 ) {
    SECURE_D->make_wizard( str );
  } else {
    write( "You need admin priveleges to make wizards.\n" );
  } 
}