import java.io.*

val br = BufferedReader(InputStreamReader(System.`in`))
fun main() {
    br.readLine()
    var sum = 0L
    var cur = 0L
    br.readLine().trim().split(" ").map { it.trim().toLong() }.forEach {
        sum += cur * it
        cur += it
    }
    println(sum)
}

