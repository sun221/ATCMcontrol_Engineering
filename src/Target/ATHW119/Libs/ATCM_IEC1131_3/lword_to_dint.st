(*[[
    UserURL= "ATCMfile:LWORD_TO_DINT.htm"
]]*)

FUNCTION LWORD_TO_DINT : DINT
VAR_INPUT 
    IN : LWORD; 
END_VAR

inline{(int)%1}

END_FUNCTION