(*[[
    UserURL= "ATCMFile:COPY_LWORD_FROM_BYTE_STRING.htm"
]]*)

(* returns a value copied from the byte string BSTR at the position POS *)

FUNCTION COPY_LWORD_FROM_BYTE_STRING : LWORD
VAR_IN_OUT
    POS : DINT;
    BSTR : BYTE_STRING;
END_VAR

    COPY_LWORD_FROM_BYTE_STRING := COPY_NUMERIC_FROM_BYTE_STRING(8,POS,BSTR);;  

END_FUNCTION