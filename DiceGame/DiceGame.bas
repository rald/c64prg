10 m%=100
20 for i=1 to 6: b%(i)=0: next i
30 gosub 241
55 input "bet on number (1-6)"; n%
60 if n% < 1 or n% > 6 then print "invalid number": goto 55
70 input "how much $"; b%
80 if b% <= 0 or b% > m% then print "invalid bet": goto 70
90 b%(n%)=b%(n%)+b%
100 m%=m%-b%
105 gosub 241
110 if m%=0 then 142
120 input "bet again (y/n)"; a$
130 if a$<>"y" and a$<>"n" then 120
140 if a$="y" then 30
142 gosub 400
150 for i=1 to 3: d%(i)=int(rnd(0)*6)+1: next i
155 print "roll:"; d%(1); d%(2); d%(3)
160 w%=0: l%=0
161 for j=1 to 6
162 for i=1 to 3
163 if j=d%(i) then w%=w%+b%(j)*2:b%(j)=0
164 next i
165 if b%(j)<>0 then l%=l%+b%(j)
166 next j
210 m%=m%+w%
220 print "you win";w%;"you lose";l%
222 gosub 400
230 if m%=0 then print "game over": end
240 goto 20
241 print "{clear}dice game"
242 print "money: $"; m%
244 gosub 300
245 return
300 for i=1 to 6: print "#";i;"-> $";b%(i): next i: return
400 print "press enter key..."
500 get a$: if a$<>chr$(13) then 500
600 return
