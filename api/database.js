/* const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'admin',
  password: 'admin',
  database: 'testimaatti'
});
module.exports = connection; */

const mysql = require('mysql');
const myConnectionString = "mysql://admin:admin@localhost:3306/testimaatti";
const connection = mysql.createPool(myConnectionString);
module.exports = connection;