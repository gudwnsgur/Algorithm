import java.io.*

val br = BufferedReader(InputStreamReader(System.`in`))
fun main() {
    br.readLine()
    br.readLine().split(" ").map { it.toInt() }.distinct().sorted().forEach { 
        print("$it ")
    }
}
