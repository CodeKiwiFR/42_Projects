cat /etc/passwd | grep -v '#' | sed -n 'n;p' | rev | cut -d ':' -f7 | sort -dr | sed -n "$FT_LINE1, $FT_LINE2 p" | sed -z 's/\n/, /g' | sed 's/, $/./'
