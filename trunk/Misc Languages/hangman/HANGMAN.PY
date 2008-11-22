# Hangman By Waseem Ilahi.
import string
from random import randint
from time import time

all_letters="ABCDEFGHIJKLMNOPQRSTUVWXYZ"

class Word:
	def __init__(self,s):
		if type (s)!=type (""):
			TypeError, "Error!"
		self.s=string.upper(s)
		self.a=[0]*len(s)
		for i in range (0,len(self.s)):
			if self.s[i]not in all_letters:
				self.a[i]=1
		self.g=""
	
	def __str__(self):
		y=''
		for i in range (0,len(self.s)):
			if self.a[i]==0:
				y = y + '_ '
			else:
				y = y + self.s[i] + ' '
		return y
		
	def guess(self,g):
		n=0
		self.g=self.g+g
		for i in range (0,len(self.s)):
			if self.s[i]==g:
				self.a[i]=1
				n=n+1
		return n
		
	def already_guessed (self,g):
		if g in self.g: return 1
		else: return 0
		
	def is_completed (self):
		return not 0 in self.a
		

class Game:

	def __init__(self):
		f=open("dictionary.txt")
		self.words=string.split(f.read(),"\n")
		self.already_done = []
		
	def is_valid (self,g):
		if len(g)!=1:return 0
		if g not in all_letters:return 0
		return 1
		
	def play (self):
		if len(self.words) == len(self.already_done):
			print "\nYou've already played all the games.\n"
			return 0
			
		r=randint(0,len(self.words)-1)
		while r in self.already_done: 
			if len(self.already_done) > len(self.words)/2:
				r = (r + 1) % len(self.words) 
			else:
				r = randint(0,len(self.words)-1)

		self.already_done.append(r)
		w=self.words[r]
		self.w=Word(w)
	        self.h=Hangman()
		while not self.w.is_completed() and not self.h.is_dead():
			self.display()
			try:
				print 'Please enter a letter: ',
				g=string.upper(raw_input())
			except:
				return -1
			if not self.is_valid(g):
				print "\nThat's not a letter!\n"
				continue
			if self.w.already_guessed(g):
				print "\nYou already tried that letter. Try again!\n"
				continue
			if self.w.guess(g):
				print "\nYes!!!\n" 
				continue
			else:
				print "\nSorry, Waseem Ilahi!\n"
				self.h.tally()

		self.display()
		if self.w.is_completed():
			print "\nYOU WIN!! GREAT JOB!!\n"
			return 1
		if self.h.is_dead():
			print "\nYou're Dead!!" + '  The word is "'+self.w.s +'".  Try again!\n'
			return 0
				

	def display (self):
		print self.w.g
		print self.h
		print self.w
				
class Hangman:

	def __init__(self):
		f=open("hangman.txt")
		self.pictures=string.split(f.read(),"$")
		self.h=0
		
	def is_dead (self):
		if self.h==len(self.pictures)-2:return 1
		
	def tally (self):
		self.h=self.h+1
		
	def __str__ (self):
		z=self.pictures[self.h]
		return z


def play():
	game=Game()
	while(1):
		r = game.play()
		c = ' '
		while c[0] not in 'yYnN':
			print '\nDo you want to play another game?',
			c = raw_input()+' '
		if c[0] not in 'Yy': break

                     
if __name__ == '__main__':
	play()
		
