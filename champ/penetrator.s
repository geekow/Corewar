.name "Penetrator"
.comment "Deeper u die"

start:
	st		r1, 6
	live	%0
	sti		r1, %:looplive, %1
	fork	%:looplive
	st 		r1, 6
	live	%0
	fork	%:spam
	ld		%0, r5
	zjmp	%:start

looplive:
	live	%0
	ld		%0, r5
	zjmp	%:looplive

spam:
	st r1, 6
	live %0
	ld %57673731, r8
	st r8, 16
	ld %57673731, r8
	st r8, 6
	ld %57673731, r8
	st r8, 26
	ld %57673731, r8
	st r8, 46
	ld %57673731, r8
	st r8, 26
	ld %57673731, r8
	st r8, 86
	ld %57673731, r8
	st r8, 66
	ld %57673731, r8
	st r8, 46
	ld %57673731, r8
	st r8, 36
	ld %57673731, r8
	st r8, 1156
	ld %57673731, r8
	st r8, 216
	ld %57673731, r8
	st r8, 856
	ld %57673731, r8
	st r8, 48226
	ld %57673731, r8
	st r8, 2846
	ld %57673731, r8
	st r8, 145226
	ld %57673731, r8
	st r8, 75286
	ld %57673731, r8
	st r8, 42366
	ld %57673731, r8
	st r8, 1046
	ld %57673731, r8
	st r8, 100036
	ld %57673731, r8
	st r8, 51156
	st r1, 6
	live %0
	ld %57673731, r8
	st r8, 8216
	ld %57673731, r8
	st r8, 8856
	ld %57673731, r8
	st r8, 848226
	ld %57673731, r8
	st r8, 82846
	ld %57673731, r8
	st r8, 8145226
	ld %57673731, r8
	st r8, 875286
	ld %57673731, r8
	st r8, 842366
	ld %57673731, r8
	st r8, 81046
	ld %57673731, r8
	st r8, 8100036
