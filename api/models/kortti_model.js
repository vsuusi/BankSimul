/*
const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where idkortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
      bcrypt.hash(kortti.pin, saltRounds, function(err, hashed_pin){
    return db.query(
      'insert into kortti (idkortti,korttinumero,idasiakas, idtili, pin) values(?,?,?,?,?)',
      [kortti.idkortti, kortti.korttinumero, kortti.idasiakas, kortti.idtili, hashed_pin],
      callback
      });
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where idkortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
        bcrypt.hash(kortti.pin, saltRounds, function(err, hashed_pin){
    return db.query(
      'update kortti set idkortti=?,korttinumero=?, idasiakas=?, idtili=?, pin=?, where idkortti=?',
      [kortti.idkortti, kortti.korttinumero, kortti.idasiakas, kortti.idtili, kortti.hashed_pin, kortti.idkortti],
      callback
    );
    
},
module.exports = kortti;
*/