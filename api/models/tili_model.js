const db = require('../database');

const tili = {
  getById: function(id, callback) {
    return db.query('select * from tili where idtili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  add: function(tili, callback) {
    return db.query(
      'insert into tili (idtili,tilinumero,saldo) values(?,?,?)',
      [tili.idtili, tili.tilinumero, tili.saldo],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili where idtili=?', [id], callback);
  },
  update: function(id, tili, callback) {
    return db.query(
      'update tili set idtili=?,tilinumero=?, saldo=? where idtili=?',
      [tili.idtili, tili.tilinumero, tili.saldo, tili.idtili],
      callback
    );
  }
};
module.exports = tili;