FUNCTION_BLOCK SR
VAR_INPUT
   S1 : BOOL;
   R  : BOOL;
END_VAR
VAR_OUTPUT
   Q1 : BOOL;
END_VAR

(*
  Q1 := (NOT R AND Q1) OR S1;
*)
inline { STDLIB(SR) }

END_FUNCTION_BLOCK