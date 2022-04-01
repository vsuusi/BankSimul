var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');
const jwt = require('jsonwebtoken');

var indexRouter = require('./routes/index');
var asiakasRouter = require('./routes/asiakas');
var loginRouter = require('./routes/login');
var korttiRouter = require('./routes/kortti');
var tiliRouter = require('./routes/tili');
var tili_asiakasRouter = require('./routes/tili_asiakas');
var tilitapahtumatRouter = require('./routes/tilitapahtumat');

var app = express();

function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]

    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)

    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)

      if (err) return res.sendStatus(403)

      req.user = user

      next()
    })};

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use(helmet());
app.use(cors());

app.use('/', indexRouter);
app.use('/asiakas', asiakasRouter);
app.use('/login', loginRouter);
app.use('/kortti', korttiRouter);
app.use('/tili', tiliRouter);
app.use('/tili_asiakas', tili_asiakasRouter);
app.use('/tilitapahtumat', tilitapahtumatRouter);
app.use(authenticateToken);

module.exports = app;