##java socket 尝试。

```kotlin
import java.net.Socket

fun main() {
    val socket: Socket = Socket("192.168.31.131", 8888);
    var inputStream = socket.getInputStream();
    var outputStream = socket.getOutputStream()
    var input = InputStreamReader(inputStream, "UTF-8")
    val content = "sdkfslkf"
    outputStream.write(content.toByteArray())
    var buffer: CharArray = CharArray(50)
    var recbuffer = ByteArray(1024);
    while (true) {
        var mess = readln()
        if (mess.length > 0) {
            mess = mess + "\n"
            outputStream.write(mess.toByteArray())
            //val sc=Scanner(System.`in`)
            var len = input.read(buffer)
            //recbuffer.toString()
            val str = String(buffer)
            System.out.println(str)
        }
    }
    socket.close()
}
```

