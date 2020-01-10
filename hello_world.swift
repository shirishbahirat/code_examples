import Foundation


let names = ["Anna", "Alex", "Brian", "Jack"] 
let count = names.count - 1
for i in 0...count {
    print("Person \(i + 1) is called \(names[i])") 
}

var occupations = [
    "Malcolm": "Captain",
    "Kaylee": "Mechanic",
]
occupations["Jayne"] = "Public Relations"

let emptyArray = [String]()
let emptyDictionary = [String: Float]()



let individualScores = [75, 43, 103, 87, 12]
var teamScore = 0
for score in individualScores {
    if score > 50 {
        teamScore += 3
    } else {
        teamScore += 1
    }
}
print(teamScore)



func makeIncrementer() -> ((Int) -> Int) {
    func addOne(number: Int) -> Int {
        return 1 + number
    }
    return addOne
}
var increment = makeIncrementer()
let rval = increment(7)
print(rval)


enum Suit {
    case spades, hearts, diamonds, clubs

    func simpleDescription() -> String {
        switch self {
        case .spades:
            return "spades"
        case .hearts:
            return "hearts"
        case .diamonds:
            return "diamonds"
        case .clubs:
            return "clubs"
        }
    }
}
let hearts = Suit.hearts
let heartsDescription = hearts.simpleDescription()

let π = 3.14159
let 你好 = "你好世界"
let 🐶🐮 = "dogcow"
print(你好)



var optionalString: String? = "Hello"
print(optionalString == nil)

var optionalName: String? = "John Appleseed"
var greeting = "Hello!"
if let name = optionalName {
    greeting = "Hello, \(name)"
}
print(greeting)

func getGasPrices() -> (Double, Double, Double) {
    return (3.59, 3.69, 3.79)
}

let prices = getGasPrices()
print(prices)

var str = "Hello World"
print(str)

for index in 1...3 {
  print(index)
}

var score = 75

if score < 60 {
  print("Failed!")
} else {
  print("Pass!")
}



let candyJar = ["Peppermints", "Gooey Bears", "Happy Ranchers"]

print(candyJar)

func fahrenheitToCelsius(fahrenheitValue : Double) -> Double { 
    var result : Double
    result = (((fahrenheitValue - 32) * 5) / 9)
    return result
}

var outdoorTemperatureInFahrenheit = 88.2
var outdoorTemperatureInCelsius = fahrenheitToCelsius(fahrenheitValue:outdoorTemperatureInFahrenheit)

print(outdoorTemperatureInCelsius)

func buildASentence(subject : String, verb : String, noun : String) -> String { 
return subject + " " + verb + " " + noun + "!"
}

var out:String = ""

out = buildASentence(subject:"Swift", verb:"is", noun:"cool")
print(out)
out = buildASentence(subject:"I", verb:"love", noun:"languages")
print(out)


let implicitInteger = 70
let implicitDouble = 70.0
let explicitDouble: Double = 70

print("Hello, world")

let label = "The width is "
let width = 94
let widthLabel = label + String(width)

print(widthLabel)

class NamedShape {
  var numberOfSides: Int = 10
  var name: String = ""

  func ini(name: String) -> String {
     return "A shape with \(numberOfSides) sides."
     }
}

let shp = NamedShape()
var bnb = shp.ini(name:"test")
print(bnb)

/*
func repeat<ItemType>(item: ItemType, times: Int) -> ItemType[] { 
    var result = ItemType[]()
    for i in 0...times {
        result += item 
    }
    return result 
}

repeat(item:"knock", times:4)
*/


func area(width: Int, height: Int) -> Int {
    return width * height
}

let ar = area(width: 10, height: 10)
print(area)

class Shape {
    var numberOfSides = 0
    func simpleDescription() -> String {
        return "A shape with \(numberOfSides) sides."
    }
}


let shpx = Shape()
let strr = shpx.simpleDescription()
print(strr)


class NameShape {
    var numberOfSides: Int = 0
    var name: String

    init(name: String) {
        self.name = name
    }

    func simpleDescription() -> String {
        return "A shape with \(numberOfSides) sides."
    }
}

class Square: NameShape {
    var sideLength: Double

    init(sideLength: Double, name: String) {
        self.sideLength = sideLength
        super.init(name: name)
        numberOfSides = 4
    }

    func area() -> Double {
        return sideLength * sideLength
    }

    override func simpleDescription() -> String {
        return "A square with sides of length (sideLength)."
    }
}

let test = Square(sideLength: 5.2, name: "my test square")
let arr = test.area()
let decs = test.simpleDescription()
print(arr, decs)


var welcomeMessage: String
welcomeMessage = "Hi there!"

print(welcomeMessage)
print("The current value of welcomeMessage is \(welcomeMessage)")


let cat = "🐱"; print(cat)

let http404Error = (404, "Not Found")

print(http404Error)

let (statusCode, statusMessage) = http404Error
print("The status code is \(statusCode)")
print("The status message is \(statusMessage)")

print("The status code is \(http404Error.0)")
print("The status message is \(http404Error.1)")


let http200Status = (statusCode: 200, description: "OK")

print("The status code is \(http200Status.statusCode)")
print("The status message is \(http200Status.description)")


let possibleString: String? = "An optional string."
let forcedString: String = possibleString! // requires an exclamation mark

let assumedString: String! = "An implicitly unwrapped optional string."
let implicitString: String = assumedString // no need for an exclamation mark


let defaultColorName = "red"
var userDefinedColorName: String?   // defaults to nil

var colorNameToUse = userDefinedColorName ?? defaultColorName

for index in 1...5 {
    print("\(index) times 5 is \(index * 5)")
}

let mnames = ["Anna", "Alex", "Brian", "Jack"]
let mcount = names.count
for i in 0..<mcount {
    print("Person \(i + 1) is called \(mnames[i])")
}


for name in mnames[2...] {
    print(name)
}


for name in mnames[...2] {
    print(name)
}

for name in mnames[..<2] {
    print(name)
}

typealias AudioSample = UInt16

var favoriteGenres: Set<String> = ["Rock", "Classical", "Hip hop"]

func greet(person: String) -> String {
    let greeting = "Hello, " + person + "!"
    return greeting
}

print(greet(person: "Anna"))

print(greet(person: "Brian"))



func arithmeticMean(_ numbers: Double...) -> Double {
    var total: Double = 0
    for number in numbers {
        total += number
    }
    return total / Double(numbers.count)
}
print(arithmeticMean(1, 2, 3, 4, 5))
print(arithmeticMean(3, 8.25, 18.75))   

let namex = ["Chris", "Alex", "Ewa", "Barry", "Daniella"]

func backward(_ s1: String, _ s2: String) -> Bool {
    return s1 > s2
}
var reversedNames = namex.sorted(by: backward)

print(reversedNames)

reversedNames = names.sorted(by: { s1, s2 in return s1 > s2 } )
print(reversedNames)
