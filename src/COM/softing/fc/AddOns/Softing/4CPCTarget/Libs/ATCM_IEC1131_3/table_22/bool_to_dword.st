
(*[[
    UserURL= "ATCM:BOOL_TO_DWORD.htm"
]]*)

FUNCTION BOOL_TO_DWORD : DWORD
VAR_INPUT 
    IN : BOOL; 
END_VAR

inline{%1?1:0}

END_FUNCTION