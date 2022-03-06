import java.io.*

private val br = BufferedReader(InputStreamReader(System.`in`))
fun main() {
    var n = br.readLine().toLong()
    val max = n
    for (i in 1..max+1) {
        n -= i
        if(n < 0) {
            println(i-1)
            return
        }
    }
}
