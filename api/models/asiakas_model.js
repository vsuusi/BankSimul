const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where idasiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (idasiakas,nimi,lahiosoite, puhelinnumero) values(?,?,?,?)',
      [asiakas.idasiakas, asiakas.nimi, asiakas.lahiosoite, asiakas.puhelinnumero],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where idasiakas=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set idasiakas=?,nimi=?, lahiosoite=?, puhelinnumero=? where idasiakas=?',
      [asiakas.idasiakas, asiakas.nimi, asiakas.lahiosoite, asiakas.puhelinnumero, asiakas.idasiakas],
      callback
    );
  }
};
module.exports = asiakas;

