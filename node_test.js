var spawn = require('child_process').spawn;
var robin = spawn('./a.out');
robin.on('exit', function (error, exitCode) {
    console.log("Child exited with code: " + exitCode);
});

var i = 0;
var lines = ['new a\n','wn a\n','I love cookies\n','rn a\n'];

robin.stdin.setEncoding('utf-8');
robin.stdout.on('data', function(data){
	console.log(data.toString());
	if(i <= lines.length){
		nextLine();
	} else {
		robin.stdin.write('exit\n');
	}
})

robin.stdin.write('hello\n');

var nextLine = function(){
	robin.stdin.write(lines[i]);
	i++;
}