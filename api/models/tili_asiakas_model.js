const db = require('../database');

const tili_asiakas = {
  getById: function(id, callback) {
    return db.query('select * from tili_asiakas where idtili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili_asiakas', callback);
  },
  add: function(tili_asiakas, callback) {
    return db.query(
      'insert into tili_asiakas (idtili,idasiakas) values(?,?)',
      [tili_asiakas.idtili, tili_asiakas.idasiakas],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili_asiakas where idtili=?', [id], callback);
  },
  update: function(id, tili_asiakas, callback) {
    return db.query(
      'update tili_asiakas set idtili=?,idasiakas=? where idtili?',
      [tili_asiakas.idtili, tili_asiakas.idasiakas],
      callback
    );
  }
};
module.exports = tili_asiakas;