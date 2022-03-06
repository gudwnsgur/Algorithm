import java.io.*

val br = BufferedReader(InputStreamReader(System.`in`))
fun main() {
    val (n, k) = br.readLine().split(" ").map { it.toInt() }
    println(br.readLine().split(" ").map { it.toInt() }.sorted()[k-1])
}

