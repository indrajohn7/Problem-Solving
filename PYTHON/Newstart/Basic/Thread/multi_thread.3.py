#!/usr/bin/python

import os
import threading
import time
import thread

class mythread(threading.Thread):
	def __init__(self, Id, name, counter):
		threading.Thread.__init__(self)
		self.Id = Id
		self.name = name
		self.counter = counter
	
	def run(self):
		while self.counter > 0:
			print("Thread %s is staring at %s" % (self.name, time.ctime(time.time())))
			time.sleep(3)
			print("Thread %s is ending at %s" % (self.name, time.ctime(time.time())))
			self.counter -= 1


def print_time(Id, name, delay):
	count = 0
	while count < 5:
		print("Man Thread %s is staring at %s" % (name, time.ctime(time.time())))
		time.sleep(delay)
		print("Man Thread %s is ending at %s" % (name, time.ctime(time.time())))
		count += 1

def __main__():
	man_thread = thread.start_new_thread(print_time, (1, "Man_thread", 3))
	my_thread = mythread(2, "New_Thread", 5)
	my_thread.start()

__main__()
