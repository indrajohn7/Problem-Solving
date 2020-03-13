#!/usr/bin/python

import smtplib

sender = 'inbanerj@akamai.com'
receivers = ['inbanerj@akamai.com']

message = """From: From Person <inbanerj@akamai.com>
To: To Person <inbanerj@akamai.com>
Subject: SMTP e-mail test

This is a test e-mail message.
"""

try:
   smtpObj = smtplib.SMTP('localhost')
   smtpObj.sendmail(sender, receivers, message)         
   print "Successfully sent email"
except:
   print "Error: unable to send email"

