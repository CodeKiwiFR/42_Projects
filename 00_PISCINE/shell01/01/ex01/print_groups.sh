id $FT_USER | sed 's/.*groups=//g' | sed 's/[[:digit:]]*(//g' | sed 's/)//g' | tr -d '\n'
