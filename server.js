const bodyParser = require('body-parser')
const express = require('express')
const app = express()

app.use(bodyParser.urlencoded({extended:true}))
app.use(express.static('public'))


app.get("/" , function(req,res){
    res.sendFile(__dirname + '/index.html')
})



app.listen(process.env.PORT || 3000 , function(){
    console.log('Server Live at Server 3000')
})