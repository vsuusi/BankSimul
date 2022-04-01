const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where idtilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (idtilitapahtumat,paivays,tapahtuma,summa,idtili,idkortti) values(?,?,?,?,?,?)',
      [tilitapahtumat.idtilitapahtumat, tilitapahtumat.paivays, tilitapahtumat.tapahtuma, tilitapahtumat.summa, tilitapahtumat.idtili, tilitapahtumat.idkortti],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where idtilitapahtumat=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set idtilitapahtumat=?,paivays=?, tapahtuma=?, summa=?, idtili=?, idkortti=? where idtilitapahtumat=?',
      [tilitapahtumat.idtilitapahtumat, tilitapahtumat.paivays, tilitapahtumat.tapahtuma, tilitapahtumat.summa, tilitapahtumat.idtili, tilitapahtumat.idkortti],
      callback
    );
  }
};
module.exports = tilitapahtumat;