const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where id_asiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (id_asiakas,nimi,lahiosoite,puhelinnumero) values(?,?,?,?)',
      [asiakas.id_asiakas, asiakas.lahiosoite, asiakas.puhelinnumero, asiakas.nimi],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where id_asiakas=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set id_asiakas=?,lahiosoite=?, puhelinnumero=?, nimi=? where id_asiakas=?',
      [asiakas.id_asiakas, asiakas.lahiosoite, asiakas.puhelinnumero,asiakas.nimi, id],
      callback
    );
  }
};
module.exports = asiakas;