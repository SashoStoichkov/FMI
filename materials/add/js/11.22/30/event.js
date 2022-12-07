class Event {
  constructor(name, capacity) {
    this.name = name;
    this.capacity = capacity;
    this.remainingCapacity = capacity;
  }

  getId() {
    return this.id;
  }

  getName() {
    return this.name;
  }

  getCapacity() {
    return this.capacity;
  }

  getRemainingCapacity() {
    return this.remainingCapacity;
  }
}

module.exports = Event;
