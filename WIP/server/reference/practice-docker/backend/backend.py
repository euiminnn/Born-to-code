import os
from flask import Flask, request, jsonify
from flask_cors import CORS
from flaskext.mysql import MySQL

app = Flask(__name__)
CORS(app)
mysql = MySQL()

# 실전에서는 비밀번호 등을 이곳에 입력하지 말 것!
# 환경변수 등을 활용하세요.
app.config['MYSQL_DATABASE_USER'] = 'mysql_user'
app.config['MYSQL_DATABASE_PASSWORD'] = 'mysql_password'
app.config['MYSQL_DATABASE_DB'] = 'visitlog'

app.config['MYSQL_DATABASE_HOST'] = os.getenv('DBHOST', 'localhost') 

mysql.init_app(app)

@app.route('/')
def index():
  return "Backend Server"

@app.route('/visits', methods=['GET'])
def readVisit():
    cur = mysql.connect().cursor()
    cur.execute('''SELECT * FROM visits''')
    r = [dict((cur.description[i][0], value)
      for i, value in enumerate(row)) for row in cur.fetchall()]
    return jsonify({'visits' : r})

@app.route('/visits', methods=['POST'])
def writeVisit():
  try:
    _name = request.json['name']
    if _name and request.method == 'POST':
      sqlQuery = "INSERT visits(visitor_name) VALUES(%s)"
      bindData = (_name)
      conn = mysql.connect()
      cursor = conn.cursor()
      cursor.execute(sqlQuery, bindData)
      conn.commit()
      respone = jsonify('Employee added successfully!')
      respone.status_code = 200
      return respone
  except Exception as e:
    print(e)
  finally:
    cursor.close() 
    conn.close()



if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)