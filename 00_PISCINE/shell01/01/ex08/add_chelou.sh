echo $FT_NBR1 + $FT_NBR2 | tr \'\\\\\"\?\! '01234' | tr 'mrdoc' '01234' | sed 's/^/obase=13;ibase=5;/' | bc | tr '[:upper:]' '[:lower:]' | tr '0123456789abc' 'gtaio luSnemf'
