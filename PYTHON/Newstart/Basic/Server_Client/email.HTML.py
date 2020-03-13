#!/usr/bin/python

import smtplib

sender = 'inbanerj@akamai.com'
receivers = ['inbanerj@akamai.com']

message = """From: From Person <inbanerj@akamai.com>
To: To Person <inbanerj@akamai.com>
MIME-Version: 1.0
Content-type: text/html
Subject: SMTP HTML e-mail test

This is an e-mail message to be sent in HTML format

<b>This is HTML message.</b>
<h1>This is headline.</h1>
"""

try:
   smtpObj = smtplib.SMTP('localhost')
   smtpObj.sendmail(sender, receivers, message)         
   print "Successfully sent email"
except:
   print "Error: unable to send email"

