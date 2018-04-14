import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.header import Header

mail_host = "smtp.mxhichina.com"  # 设置服务器
mail_user = "talosl@dctwr.cn"  # 用户名
mail_pass = "***************"  # 口令

sender = 'talosl@dctwr.cn'
receivers = '592157602@qq.com' # 接收邮件

message = MIMEMultipart()
message['From'] = Header("四则运算器", 'utf-8')
message['To'] = Header("测试", 'utf-8')
subject = '运算测试'
message['Subject'] = Header(subject, 'utf-8')

# 邮件正文内容
message.attach(MIMEText('12345', 'plain', 'utf-8'))


att1 = MIMEText(open('question.txt', 'rb').read(), 'base64', 'utf-8')
att1["Content-Type"] = 'application/octet-stream'
att1["Content-Disposition"] = 'attachment; filename="question.txt"'
message.attach(att1)


att2 = MIMEText(open('answer.txt', 'rb').read(), 'base64', 'utf-8')
att2["Content-Type"] = 'application/octet-stream'
att2["Content-Disposition"] = 'attachment; filename="answer.txt"'
message.attach(att2)

try:
    smtpObj = smtplib.SMTP()
    smtpObj.connect(mail_host, 25)  
    smtpObj.login(mail_user, mail_pass)
    smtpObj.sendmail(sender, receivers, message.as_string())
    print ("邮件发送成功")
except smtplib.SMTPException:
    print ("Error: 无法发送邮件")
