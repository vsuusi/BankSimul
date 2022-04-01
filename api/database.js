const mysql = require('mysql');
const dotenv = require('dotenv');
dotenv.config();
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: 'password',
  database: 'testimaatti'
});
module.exports = connection; 

