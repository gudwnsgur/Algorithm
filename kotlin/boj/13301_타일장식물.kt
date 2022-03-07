import java.io.*

val br = BufferedReader(InputStreamReader(System.`in`))
fun main() {
    generateSequence(Pair(0L,1L)) { Pair(it.second, it.first+it.second)}.elementAt(br.readLine().toInt()).run {
        println(first*2 + second*2)
    }
}

