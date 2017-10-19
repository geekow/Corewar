.name "my 42 champ"
.comment "STAYING ALIVE"

first: sti r1,%:second,r2
		live %1

second:	live %1

third: fork %:fourth

fourth:	live %1
		zjmp %:first